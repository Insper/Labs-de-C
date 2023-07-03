import json
import os
import re
from pathlib import Path

from dotenv import load_dotenv
from mkdocs.config import base
from mkdocs.config import config_options as c
from mkdocs.plugins import BasePlugin

from .exercise_manager import ExerciseManager

CWD = Path.cwd()
HERE = Path(__file__).parent

load_dotenv(CWD / ".env")


class ActiveHandoutPluginConfig(base.Config):
    telemetry = c.Type(bool, default=False)
    backend_url = c.Type(str, default='')
    course_slug = c.Type(str, default='')
    tag_tree = c.Type(list, default=[])
    plugin_exercise_counter = c.Type(bool, default=True)

class ActiveHandoutPlugin(BasePlugin[ActiveHandoutPluginConfig]):
    def _setupURLs(self, config):
        BACKEND_URL = os.getenv('BACKEND_URL')
        if BACKEND_URL:
            self.config.backend_url = BACKEND_URL

        backend_url = self.config.backend_url
        if not backend_url:
            print('backend_url is not set, no server interaction will occur')
            return config
        config['backend_url'] = backend_url

        slash = ''
        if not backend_url.endswith('/'):
            slash = '/'

        config['backend_user_menu_url'] = os.getenv('BACKEND_USER_MENU_URL', f'{backend_url}{slash}user-menu')

        return config

    def on_config(self, config):
        try:
            locale = str(config['theme']['locale'])
            config['mdx_configs']['active-handout-plugins'] = {'locale': locale}
        except KeyError:
            print('No locale set, using default')

        config['markdown_extensions'].append('active-handout-plugins')

        if self.config.telemetry:
            if not self.config.course_slug:
                print('Disabling telemetry. The variable course_slug is not set. You must set it at your mkdocs.yml.')
                self.config.telemetry = False
            else:
                config['COURSE_SLUG'] = self.config.course_slug

        self.exercise_manager = ExerciseManager(self.config.course_slug)

        active_handout_config = {
            'telemetry': self.config.telemetry,
            'tag_tree': self.config.tag_tree,
            'exercise_manager': self.exercise_manager,
        }

        config['PLUGIN_EXERCISE_COUNTER'] = self.config.plugin_exercise_counter

        config['active_handout'] = self._setupURLs(active_handout_config)


        return config

    def on_page_markdown(self, markdown, page, config, files):
        active_handout_config = config['mdx_configs'].setdefault('active-handout-plugins', {})
        active_handout_config['page'] = page
        active_handout_config['mkdocs_config'] = config

        # Saves the used seed on the last line of the page.
        # This line is later removed in on_page_content
        return markdown + "\n<!--{{seed}} REMOVE ME-->"

    def on_page_content(self, html: str, *, page, config, files):
        seed = 0
        matches = re.findall(r'\<\!\-\-(\d+) REMOVE ME\-\-\>', html)
        if len(matches) > 0:
            seed = int(matches[0])

        html = re.sub(r'^(<div class\=\"admonition exercise.*\" id=)\"(.*)\">$',
                   r'\1"\2_' f'{seed}">', html, flags=re.MULTILINE)

        html_without_seed = re.sub(r'\<\!\-\-.*REMOVE ME\-\-\>', '', html)
        return html_without_seed

    def on_post_build(self, *, config) -> None:
        tag_mappings = {}
        try:
            with open('exercise_data.json') as f:
                prev_data = json.load(f)
                tag_mappings = prev_data.get('tags', {})
        except FileNotFoundError:
            pass

        with open('exercise_data.json', 'w') as f:
            f.write(self.exercise_manager.exercise_json(tag_mappings))
