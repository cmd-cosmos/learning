### Emulating a compiler ---> based on the compilation mountain

def tokenizer(command_string) -> list:
    '''
    Lexer ---> lexicographic split of the command passed in
    returns tokens based on each line of text instruction
    '''
    tokens = []
    tokens = command_string.split()
    return tokens

print(tokenizer("var x = 100 + 100"))
