#!/usr/bin/env python3
from markdown.test_tools import TestCase

class TestTemplatingCustomVariables(TestCase):
    default_kwargs = {
            'output_format': 'html',
            'extensions': ['admonition', 'active-handout-plugins'],
            'extension_configs': {
                'active-handout-plugins': {
                    'custom_variables': {
                        'bla1': 'var1value',
                        'def2': 'var2value'
                    }
                }
            }
            }

    def test_undefined_variable_pass_through(self):
        self.assertMarkdownRenders(
            self.dedent('''
            {{ bla }}
            '''),

          self.dedent('''
            <section class="progress-section show">
            <p>{{ bla }}</p>
            </section>
          ''')
            )

    def test_custom_variables(self):
        self.assertMarkdownRenders(
            self.dedent('''
            {{ bla1 }}
            '''),

          self.dedent('''
            <section class="progress-section show">
            <p>var1value</p>
            </section>
          ''')
            )

    def test_operation(self):
        self.assertMarkdownRenders(
            self.dedent('''
            {{ bla1 + def2 }}
            '''),

          self.dedent('''
            <section class="progress-section show">
            <p>var1valuevar2value</p>
            </section>
          ''')
            )
