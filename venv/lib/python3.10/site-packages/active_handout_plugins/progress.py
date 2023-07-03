from markdown.treeprocessors import Treeprocessor
import xml.etree.ElementTree as etree
import html

from .admonition import AdmonitionVisitor
from .l10n import gettext as _


class ProgressButtons(AdmonitionVisitor):
    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self.count = 0

    def visit(self, el):
        if not 'progress' in el.attrib['class'].split():
            return

        title_p = el.find("p[@class='admonition-title']")

        html_button = f'<div class="ah-progress-container"><button id="prog-{self.count}" class="ah-button ah-button--primary progress"> {_(title_p.text)} </button></div>'
        el.clear()
        el.append(etree.fromstring(html_button))
        self.count += 1


class SplitDocumentInSections(Treeprocessor):
    def run(self, root):
        current_section = []
        sections = []
        for el in root:
            current_section.append(el)
            if 'class' in el.attrib and 'progress' in el.attrib['class']:
                sections.append(current_section)
                current_section = []

        sections.append(current_section)
        for i, section in enumerate(sections):
            sec_element = etree.SubElement(root, 'section')
            sec_element.attrib["class"] = "progress-section"
            if i == 0:
                sec_element.attrib["class"] += " show"
            for el in section:
                root.remove(el)
                sec_element.append(el)
