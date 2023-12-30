import unittest
def get_name(first,last):
    full = first + ' ' + last
    return full.title()

class NamesTest(unittest.TestCase):
    def test_first_last_name(self):
        fname = get_name('dreaife','he')
        self.assertEqual(fname,'Dreaife He')

# a = NamesTest()
# a.test_name()
# get_name('dreaife','he')
unittest.main()