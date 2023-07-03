import json
from urllib.parse import quote_plus, urljoin

from .admonition import AdmonitionVisitor
from .l10n import gettext as _


class DashboardAdmonition(AdmonitionVisitor):
    def visit(self, el):
        if not 'dashboard' in el.attrib['class']:
            return

        title = el.find('p/[@class="admonition-title"]')
        el.remove(title)

        el.attrib['class'] = 'dashboard-container'
        safe_course_slug = quote_plus(self.mkdocs_config["COURSE_SLUG"])
        active_handout_config = self.mkdocs_config['active_handout']
        safe_tag_tree = quote_plus(json.dumps(active_handout_config['tag_tree']))
        dashboard_url = urljoin(
            active_handout_config['backend_url'],
            f'../dashboard/{safe_course_slug}/student?tag-tree={safe_tag_tree}'
        )
        el.attrib['hx-get'] = dashboard_url
        el.attrib['hx-trigger'] = "token-ready"
