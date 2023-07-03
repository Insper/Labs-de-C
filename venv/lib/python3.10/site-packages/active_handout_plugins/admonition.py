from markdown.treeprocessors import Treeprocessor

from .l10n import gettext as _


class AdmonitionVisitor(Treeprocessor):
    def __init__(self, *args, **kwargs):
        self.page = kwargs.pop('page', None)
        self.mkdocs_config = kwargs.pop('mkdocs_config', {})

        super().__init__(*args, **kwargs)

    def has_class(self, el, classes_to_search):
        el_classes = el.get("class", "").split()
        classes_found = [cls for cls in el_classes if cls in classes_to_search]
        if len(classes_found) > 0:
            return classes_found[0]

        return None

    def match(self, el):
        raise NotImplemented()

    def run(self, root):
        for el in root.findall(".//p[@class='admonition-title']/.."):
            title = el.find("p[@class='admonition-title']")
            if title.text:
                title.text = _(title.text)
            self.visit(el)

    def visit(self, el):
        raise NotImplemented()


class AdmonitionVisitorSelector(AdmonitionVisitor):
    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self.__visitors = []

    def register(self, visitor, weight):
        self.__visitors.append((weight, visitor))
        self.__visitors.sort(reverse=True, key=lambda v: v[0])

    @property
    def visitors(self):
        for _, v in self.__visitors:
            yield v

    def __select_visitor(self, el):
        """Return the first match based on the priority"""

        for visitor in self.visitors:
            if visitor.match(el):
                return visitor
        return None

    def visit(self, el):
        visitor = self.__select_visitor(el)
        if visitor:
            visitor.visit(el)
