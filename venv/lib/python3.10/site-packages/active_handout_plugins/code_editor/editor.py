import re
from ..admonition import AdmonitionVisitor
from .utils import extract_files, remove_admonition_title


class CodeEditorAdmonition(AdmonitionVisitor):
    def visit(self, el):
        if 'code-editor' not in el.attrib['class']:
            return

        remove_admonition_title(el)
        files = extract_files(el, self.md.htmlStash)

        editors = ''
        filenames = ''
        is_first = True
        for filename, file_data in files.items():
            tab_classes = 'tab'
            editor_classes = 'file-content'
            if file_data['is_hidden']:
                editor_classes += ' hidden-file'
            else:
                lock_icon = ''
                readonly = 'false'
                if is_first and not file_data['is_readonly']:
                    tab_classes += ' active'
                    editor_classes += ' active'
                    is_first = False
                if file_data['is_readonly']:
                    readonly = 'true'
                    lock_icon = '<svg class="svg-icon" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 15v2m-6 4h12a2 2 0 002-2v-6a2 2 0 00-2-2H6a2 2 0 00-2 2v6a2 2 0 002 2zm10-10V7a4 4 0 00-8 0v4h8z"></path></svg>'

                filenames += f'<li class="{ tab_classes }">{ lock_icon }{ filename }</li>'
            editors += f'<div class="{ editor_classes }" data-readonly="{ readonly }" data-language="{ file_data["language"] }" data-filename="{ filename }">{ file_data["code"] }</div>'

        editor_html = f'''
        <div class="file-editor">
            <ul class="file-tab">{filenames}</ul>
            <div class="file-content-container">
                { editors }
            </div>
            <div class="editor-controls">
                <button class="ah-button ah-button--borderless editor-reset-btn" type="button">
                    <svg focusable="false" aria-hidden="true" viewBox="0 0 24 24" data-testid="RestartAltIcon" aria-label="fontSize large"><path d="M12 5V2L8 6l4 4V7c3.31 0 6 2.69 6 6 0 2.97-2.17 5.43-5 5.91v2.02c3.95-.49 7-3.85 7-7.93 0-4.42-3.58-8-8-8zm-6 8c0-1.65.67-3.15 1.76-4.24L6.34 7.34C4.9 8.79 4 10.79 4 13c0 4.08 3.05 7.44 7 7.93v-2.02c-2.83-.48-5-2.94-5-5.91z"></path></svg>
                </button>
            </div>
        </div>
        '''
        el.attrib['class'] = re.sub('(?=\s*)admonition(\s|$)', '', el.attrib['class'])
        el.text = self.md.htmlStash.store(editor_html)
