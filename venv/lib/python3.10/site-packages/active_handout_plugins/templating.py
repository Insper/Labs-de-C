from markdown.postprocessors import Postprocessor
from markdown.preprocessors import Preprocessor
from jinja2 import Environment, FileSystemLoader, Undefined
import random
import string
import os
import math
import sys
import logging
from mkdocs.utils import warning_filter

LOG = logging.getLogger('mkdocs.plugins.active_handout')
LOG.addFilter(warning_filter)

class RandomIntVariable:
    def __init__(self):
        self.new()

    def new(self, start=0, end=10):
        self.value = random.randint(start, end)
        return self.value

    def __str__(self):
        return str(self.value)


class RandomFloatVariable:
    def __init__(self):
        self.new()

    def new(self, start=0, end=10):
        sz = end - start
        self.value = sz * random.random() + start
        return self.value

    def __str__(self):
        return str(self.value)


class RandomStringVariable:
    def __init__(self):
        self.new()

    def new(self, sz=10):
        self.value = ''.join([random.choice(string.ascii_letters) for _ in range(sz)])
        return self.value

    def __str__(self):
        return str(self.value)


class Chooser:
    def __init__(self):
        pass

    def __call__(self, *args):
        return random.choice(args)


class Counter:
    def __init__(self):
        self.value = 0

    def __str__(self):
        self.value += 1
        return str(self.value)


class SetSeed:
    def __init__(self):
        self(0)
    
    def __call__(self, s):
        self.seed = s
        random.seed(s)

    def __str__(self):
        return str(self.seed)

class UndefinedPrint(Undefined):
    def __str__(self):
        LOG.warning(self._undefined_message)
        return f'{{{{ {self._undefined_name} }}}}'

class Jinja2PreProcessor(Preprocessor):
    def __init__(self, md, user_provided_variables):
        super().__init__(md)
        self.user_provided_variables = user_provided_variables

    def run(self, lines):
        text = '\n'.join(lines)
        loader = FileSystemLoader(os.getcwd())
        e = Environment(loader=loader, extensions=['jinja2.ext.do'], undefined=UndefinedPrint)
        custom_template_values = {
            'choice': Chooser(),
            'seed': SetSeed(),
            'count': Counter(),
            'math': math,
        }
        custom_template_values.update(
            {f'randint{i}': RandomIntVariable() for i in range(1, 11)}
        )
        custom_template_values.update(
            {f'randfloat{i}': RandomFloatVariable() for i in range(1, 11)}
        )
        custom_template_values.update(
            {f'randstring{i}': RandomStringVariable() for i in range(1, 11)}
        )
        custom_template_values.update(self.user_provided_variables)
        new_text = e.from_string(text).render(custom_template_values)

        return new_text.split('\n')
