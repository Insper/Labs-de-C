from .exercise import ExerciseAdmonition
from .l10n import gettext as _
import random
import xml.etree.ElementTree as etree


class ParsonsExercise(ExerciseAdmonition):
    def __init__(self, *args, **kwargs) -> None:
        super().__init__('exercise', ['parsons'], *args, **kwargs)

    def create_exercise_form(self, el, submission_form):
        el_id = el.get('id', '')
        without_indent = 'no-indent' in el.get('class', "").split()

        code = submission_form.findall('*')[-2]
        end_char = code.text.find("\x03")
        start_index = code.text.find(":") + 1
        html_idx = int(code.text[start_index:end_char])
        processed_code = self.md.htmlStash.rawHtmlBlocks[html_idx]

        start_index = processed_code.find("<code>") + 6
        lines = processed_code.split("\n")[:-1]
        lines[0] = lines[0][start_index:]

        drag_blocks_str = _('Drag blocks from here')
        drop_blocks_str = _('Drop blocks here')

        remove_indent_btn = '<button type="button" class="ah-button ah-button--borderless indent-btn indent-btn--remove" disabled>&lt;</button>'
        add_indent_btn = '<button type="button" class="ah-button ah-button--borderless indent-btn indent-btn--add">&gt;</button>'
        if without_indent:
            remove_indent_btn = ''
            add_indent_btn = ''

        random.shuffle(lines)
        left_panel = f'''
<div class="parsons-outer-container">
    <span class="parsons-block-description">{drag_blocks_str}</span>
    <div class="parsons-container highlight original-code">
        <pre><code class="parsons-area parsons-drag-area">
'''
        for i, l in enumerate(lines):
            l_no_indent = l.replace('    ', '')
            left_panel += f'''
            <div id="{el_id}-line-{i}" class="parsons-line-container" data-linecount={i}>
                {remove_indent_btn}
                <div class="parsons-line">{l_no_indent}</div>
                {add_indent_btn}
            </div>
            '''.strip()
        left_panel += '</code></pre></div></div>'

        right_panel = f'''
<div class="parsons-outer-container">
    <span class="parsons-block-description">{drop_blocks_str}</span>
    <div class="parsons-container highlight parsons-drop-div">
        <pre><code class="parsons-area parsons-drop-area"></code></pre>
    </div>
</div>
'''
        code.set("class", "parsons-code")
        code.tag = 'div'
        code.text = self.md.htmlStash.store(left_panel + right_panel)

        parse_html = etree.fromstring(processed_code)
        self.full_answer = "".join(parse_html.itertext())
        full_answer_html = f'''<pre class="parsons-answer">{self.full_answer}</pre>'''
        if self.page and self.page.meta and self.page.meta.get("show_answers", True) == False:
            full_answer_html = ''

        reset_str = _('Reset')
        test_str = _('Test')

        reset_button_value = f'''<input type="button" class="ah-button ah-button--borderless" name="resetButton" value="{reset_str}"/>'''
        if self.page and self.page.meta and self.page.meta.get("show_reset_button", True) == False:
            reset_button_value = ''

        return f'''
        <input type="hidden" name="data" value=""/>
        {full_answer_html}
        <div class="ah-btn-group">
            {reset_button_value}
            <input type="button" class="ah-button ah-button--primary" name="sendButton" value="{test_str}"/>
        </div>
        '''

    def create_answer(self):
        if self.page and self.page.meta and self.page.meta.get("show_answers", True) == False:
            return ''

        answer_str = _('Answer')
        wrong_str = _('Wrong answer')
        correct_str = _('Correct answer')

        return f'''
<p class="admonition-title">{answer_str}</p>
<p class="wrong-answer">{wrong_str}</p>
<p class="correct-answer">{correct_str}</p>
'''

    def get_tags(self, el):
        return ['parsons-exercise']

    def get_meta(self):
        return {
            'answer': self.full_answer
        }
