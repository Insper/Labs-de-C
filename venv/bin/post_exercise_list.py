import argparse
import json
import sys
from pathlib import Path
from urllib.parse import quote_plus

import requests
import yaml

MKDOCS_CONFIG = 'mkdocs.yml'
EXERCISE_DATA = 'exercise_data.json'


def load_backend_from_config(root_dir):
    with open(root_dir / MKDOCS_CONFIG) as f:
        config = yaml.load(f, yaml.Loader)
    plugins = config.get('plugins', [{}])
    if hasattr(plugins, 'get'):
        active_handout = plugins.get('active-handout', {})
    else:
        for plugin in plugins:
            if 'active-handout' in plugin:
                active_handout = plugin['active-handout']
    backend_url = active_handout.get('backend_url')
    if not backend_url:
        print("Backend url is not set in mkdocs.yml. Can't post exercise data.")
        sys.exit()
    return backend_url


def load_data(root_dir):
    if not (root_dir / EXERCISE_DATA).is_file():
        print(f"File {EXERCISE_DATA} does not exist. Can't post data.")
        sys.exit()

    with open(EXERCISE_DATA) as f:
        return json.load(f)


def post_data(url, token, exercise_list):
    res = requests.post(
        url,
        json=exercise_list,
        headers={'Authorization': f'Token {token}'},
    )

    content = res.content.decode('utf-8')
    if res.status_code == 200:
        print(f'Success!\n{content}')
    else:
        print(f'Failed with error:\n{content}')


parser = argparse.ArgumentParser(
    description = "Active Handout's script that posts exercise list from exercise_data.json to backend server"
)
parser.add_argument('token', help='Admin user token.')
parser.add_argument('--dir', default='.', help='Root directory that contains the mkdocs.yml and exercise_data.json files')
parser.add_argument('--backend', '-b', default='', help='Backend URL. If not provided, will try to load from mkdocs.yml.')
args = parser.parse_args()

token = args.token
root_dir = Path(args.dir)
backend_url = args.backend or load_backend_from_config(root_dir)
if not backend_url.endswith('/'):
    backend_url += '/'
data = load_data(root_dir)
course_slug = quote_plus(data['course'])
exercise_list = data['exercises']
tag_mappings = data['tags']

post_data(f'{backend_url}exercises/{course_slug}', token, exercise_list)
post_data(f'{backend_url}tags/{course_slug}/names', token, tag_mappings)
