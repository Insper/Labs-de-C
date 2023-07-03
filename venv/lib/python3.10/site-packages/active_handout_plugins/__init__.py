from markdown import Extension

from .l10n import init_l10n
# Keep AdmonitionVisitor here so it's easier to import it in other project
from .admonition import AdmonitionVisitorSelector, AdmonitionVisitor
# Keep ExerciseAdmonition here so it's easier to import it in other project
from .exercise import ChoiceExercise, SelfProgressExercise, TextExercise, ExerciseAdmonition
from .progress import ProgressButtons, SplitDocumentInSections
from .counter import CounterProcessor
from .video import VideoAdmonition
from .pdf import PdfAdmonition
from .parsons import ParsonsExercise
from .templating import Jinja2PreProcessor
from .code_editor.editor import CodeEditorAdmonition
from .dashboard import DashboardAdmonition


class ActiveHandoutExtension(Extension):
    """ Admonition extension for Python-Markdown. """
    config = {
        'page': ['', 'This setting is filled automatically by our mkdocs extension. Do not modify.'],
        'mkdocs_config': [{}, 'This setting is filled automatically by our mkdocs extension. Do not modify.'],
        'locale': ['en', 'locale should be the same as for the theme'],
        'custom_variables': [{}, 'Dictionary mapping variable names to use in Jinja templating extension'],
    }

    def extendMarkdown(self, md):
        """ Add Admonition to Markdown instance. """
        md.registerExtension(self)

        self.page = self.getConfig('page', '')
        self.mkdocs_config = self.getConfig('mkdocs_config', {})
        init_l10n(self.getConfig('locale'))

        exercise_admonitions = AdmonitionVisitorSelector(md, page=self.page, mkdocs_config=self.mkdocs_config)
        register_exercise_visitor_builder(ChoiceExercise, 3)
        register_exercise_visitor_builder(TextExercise, 2)
        register_exercise_visitor_builder(ParsonsExercise, 2)
        register_exercise_visitor_builder(SelfProgressExercise, 1)
        self._register_exercise_visitors(exercise_admonitions, md)

        md.treeprocessors.register(SplitDocumentInSections(md), 'sections', 16)
        md.treeprocessors.register(exercise_admonitions, 'exercises', 15)
        register_treeprocessor_builder(VideoAdmonition, 'video-admonition', 15)
        register_treeprocessor_builder(PdfAdmonition, 'pdf-admonition', 15)
        if self.mkdocs_config['PLUGIN_EXERCISE_COUNTER']:
            register_treeprocessor_builder(CounterProcessor, 'counter', 15)
        register_treeprocessor_builder(ProgressButtons, 'progress', 15)
        register_treeprocessor_builder(CodeEditorAdmonition, 'code-editor', 20)
        register_treeprocessor_builder(DashboardAdmonition, 'dashboard', 15)
        self._register_treeprocessors(md)


        custom_variables = self.getConfig('custom_variables')
        if 'custom_variables' in self.mkdocs_config.get('extra', {}):
            custom_variables.update(self.mkdocs_config['extra']['custom_variables'])
        md.preprocessors.register(Jinja2PreProcessor(md, custom_variables), 'templating', 1000000000)

    def _register_exercise_visitors(self, exercise_admonitions, md):
        for weight, visitor_builders in _registered_visitors.items():
            for visitor_builder in visitor_builders:
                exercise_admonitions.register(visitor_builder(md, page=self.page, mkdocs_config=self.mkdocs_config), weight)

    def _register_treeprocessors(self, md):
        for builder, name, priority in _registered_processors:
            md.treeprocessors.register(builder(md, page=self.page, mkdocs_config=self.mkdocs_config), name, priority)


_registered_visitors = {}
def register_exercise_visitor_builder(visitor_builder, weight):
    _registered_visitors.setdefault(weight, set()).add(visitor_builder)


_registered_processors = []
def register_treeprocessor_builder(processor_builder, name, priority):
    _registered_processors.append((processor_builder, name, priority))
