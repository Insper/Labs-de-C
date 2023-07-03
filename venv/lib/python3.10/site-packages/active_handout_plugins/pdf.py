import xml.etree.ElementTree as etree

from .admonition import AdmonitionVisitor


class PdfAdmonition(AdmonitionVisitor):
    def visit(self, el):
        if not 'pdf' in el.attrib['class']:
            return

        img_el = el.find("p/img")
        if img_el is not None:
            src = img_el.attrib['src']
            html = f'<center><embed width="80%" height="300" type="application/pdf" src="{src}" /></center>'
            pdf_el = etree.fromstring(html)
            el.clear()
            el.append(pdf_el)
