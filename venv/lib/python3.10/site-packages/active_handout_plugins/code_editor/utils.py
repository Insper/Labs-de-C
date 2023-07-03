import re


def remove_admonition_title(el):
    titles = el.findall("p[@class='admonition-title']")
    for title in titles:
        el.remove(title)


def extract_files(el, html_stash):
    files = {}
    for code_element in el.findall('*'):
        code_html = _find_code_html(code_element, html_stash)
        if code_html:
            code = _extract_code(code_html)
            language = _extract_language(code_html)
            filename = f'{_extract_filename(code_html)}.{language}'
            is_hidden = _check_hidden(code_html)
            is_readonly = _check_readonly(code_html)
            files[filename] = {
                'code': code,
                'is_hidden': is_hidden,
                'is_readonly': is_readonly,
                'language': language,
            }

            el.remove(code_element)

    return files


def _find_code_html(code_element, html_stash):
    if code_element is None or not code_element.text:
        return None

    end_char = code_element.text.find("\x03")
    start_index = code_element.text.find(":") + 1
    try:
        html_idx = int(code_element.text[start_index:end_char])
    except ValueError:
        return None

    return html_stash.rawHtmlBlocks[html_idx]


def _extract_code(code_html):
    return re.sub('<[^>]+>', '', code_html)


def _extract_language(code_html):
    match = re.match(r'<div[^>]*language-(\S*)[^>]*>', code_html)
    if match:
        return match.group(1)
    return 'raw'


def _extract_filename(code_html):
    match = re.match(r'<div[^>]*filename-(\S*)[^>]*>', code_html)
    if match:
        return match.group(1)
    return 'index'


def _check_hidden(code_html):
    return bool(re.match(r'<div[^>]*hidden-file(\S*)[^>]*>', code_html))


def _check_readonly(code_html):
    return bool(re.match(r'<div[^>]*readonly-file(\S*)[^>]*>', code_html))
