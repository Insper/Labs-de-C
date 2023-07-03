import json
from collections import namedtuple
from unittest import TestCase

from ..exercise_manager import ExerciseManager

ExerciseTuple = namedtuple('ExerciseTuple', ['url', 'el_id', 'tags', 'meta', 'slug'])


class TestExerciseManager(TestCase):
    def setUp(self):
        self.course_slug = 'everything-everywhere-all-at-once'
        self.manager = ExerciseManager(self.course_slug)
        pass

    def test_create_slug_from_url_with_slug(self):
        url = '/page/with/exercises/'
        el_id = 'text-exercise-1'
        slug = self.manager.add_exercise(url, el_id, [])
        self.assertEqual(f'{url}{el_id}', slug)

    def test_create_slug_from_url_without_slug(self):
        url = '/page/with/exercises'
        el_id = 'text-exercise-1'
        slug = self.manager.add_exercise(url, el_id, [])
        self.assertEqual(f'{url}/{el_id}', slug)

    def test_create_json(self):
        url1 = '/page/with/exercises/'
        url2 = '/other/page'

        exercise1 = ExerciseTuple(
            url1,
            'text-exercise-1',
            ['tag1', 'tag2'],
            {'answer': 'This is the answer'},
            '/page/with/exercises/text-exercise-1',
        )
        exercise2 = ExerciseTuple(
            url2,
            'choice-exercise-1',
            ['tag3', 'tag4'],
            {'answer': 2},
            '/other/page/choice-exercise-1',
        )
        exercise3 = ExerciseTuple(
            url2,
            'choice-exercise-2',
            ['tag1', 'tag3'],
            {'answer': 3},
            '/other/page/choice-exercise-2',
        )
        exercises = [exercise1, exercise2, exercise3]

        for exercise in exercises:
            self.manager.add_exercise(*exercise[:-1])

        expected = {
            'course': self.course_slug,
            'exercises': {
                url1: {
                    exercise1.el_id: {
                        'tags': exercise1.tags,
                        'slug': exercise1.slug,
                        'answer': exercise1.meta['answer'],
                    },
                },
                url2: {
                    exercise2.el_id: {
                        'tags': exercise2.tags,
                        'slug': exercise2.slug,
                        'answer': exercise2.meta['answer'],
                    },
                    exercise3.el_id: {
                        'tags': exercise3.tags,
                        'slug': exercise3.slug,
                        'answer': exercise3.meta['answer'],
                    },
                }
            }
        }
        received = json.loads(self.manager.exercise_json())
        self.assertEqual(expected, received)
