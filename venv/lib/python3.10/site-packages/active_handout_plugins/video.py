import xml.etree.ElementTree as etree
import re

from .admonition import AdmonitionVisitor


class VideoAdmonition(AdmonitionVisitor):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.re = re.compile(r'(https?://)?(www\.)?(youtube|youtu|youtube-nocookie)\.(com|be)/(watch\?v=|embed/|v/|.+\?v=)?(?P<id>[A-Za-z0-9\-=_]{11})')

    def visit(self, el):

        if not 'video' in el.attrib['class']:
            return

        img_el = el.find("p/img")
        if img_el is not None:
            src = img_el.attrib['src']
            m = self.re.match(src)

            if m:
                html = f'<iframe width="100%" height="500" type="text/html" src="https://www.youtube.com/embed/{m.group("id")}?autoplay=0"></iframe>'
            else:
                html = f'<video width="100%" src="{src}" controls="true" />'

            video_el = etree.fromstring(html)
            el.clear()
            el.append(video_el)
