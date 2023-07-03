from .admonition import AdmonitionVisitor
from .l10n import gettext as _


class CounterProcessor(AdmonitionVisitor):
    TO_COUNT = ['tip', 'exercise']

    def run(self, root):
        self.counters = {adm: 0 for adm in CounterProcessor.TO_COUNT}
        super().run(root)

    def visit(self, el):
        for c in self.counters.keys():
            if c in el.attrib['class']:
                title = el.find("p[@class='admonition-title']")
                self.counters[c] += 1
                title.text = f'{_(title.text)} {self.counters[c]}'
