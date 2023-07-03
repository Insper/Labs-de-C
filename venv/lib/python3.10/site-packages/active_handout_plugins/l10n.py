import gettext as gt
from pathlib import Path


PWD = Path(__file__).parent
LOCALE_DIR = PWD / '..' / 'active_handout_theme' / 'locales'
DOMAIN = 'messages'

_language = None
def init_l10n(lang):
    global _language
    _language = gt.translation(DOMAIN, localedir=LOCALE_DIR.resolve(), languages=[lang], fallback=True)
    _language.install()


def gettext(*args, **kwargs):
    if _language:
        return _language.gettext(*args, **kwargs)
    return gt.gettext(*args, **kwargs)


def __translations():
    # This function is never called. This is just a trick to make gettext
    # detect the strings so they can be translated.
    _ = lambda x: x
    TRANSLATIONS = [_('Tip'), _('Exercise'), _('Answer'), _('Progress'), _('Warning'), _('Danger')]
