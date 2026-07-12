#pylint: skip-file

def is_palindrome(text):
    cleaned = text.lower().replace(" ", "")
    return cleaned == cleaned[::-1]

def reverse(text):
    return text[::-1]