from markdown.test_tools import TestCase

class TestVideoAdmonition(TestCase):
    default_kwargs = {
            'output_format': 'html',
            'extensions': ['admonition', 'active-handout-plugins']
            }

    def test_local_video_link(self):
        self.assertMarkdownRenders(
            self.dedent('''
            !!! video
                ![sad](aaa.mp4)
            '''),

          self.dedent('''
            <section class="progress-section show">
            <div>
            <video controls="true" src="aaa.mp4" width="100%"></video>
            </div>
            </section>
          ''')
            )

    def test_youtube_link(self):
        self.assertMarkdownRenders(
            self.dedent('''
            !!! video
                ![Title](https://www.youtube.com/watch?v=Ni709gut3RE)
            '''),

          self.dedent('''
            <section class="progress-section show">
            <div>
            <iframe height="500" src="https://www.youtube.com/embed/Ni709gut3RE?autoplay=0" type="text/html" width="100%"></iframe>
            </div>
            </section>
          ''')
            )



    def test_youtube_with_channel(self):
        self.assertMarkdownRenders(
            self.dedent('''
            !!! video
                ![](https://www.youtube.com/watch?v=fmUkZNA9ECc&ab_channel=JamessonLeandro)
            '''),

          self.dedent('''
            <section class="progress-section show">
            <div>
            <iframe height="500" src="https://www.youtube.com/embed/fmUkZNA9ECc?autoplay=0" type="text/html" width="100%"></iframe>
            </div>
            </section>
          ''')
            )




