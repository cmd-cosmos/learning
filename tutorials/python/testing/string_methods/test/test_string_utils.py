#pylint: skip-file

from src.string_utils import is_palindrome, reverse

def test_palindrome_true():
    assert is_palindrome("Never odd or even")

def test_palindrome_false():
    assert not is_palindrome("I am batman")

def test_reverse():
    return reverse("hello") == "olleh"

