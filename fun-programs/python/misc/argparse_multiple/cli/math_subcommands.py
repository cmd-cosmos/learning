#pylint: skip-file

def register_math_cmd(subparsers):
    math_parser = subparsers.add_parser("math", help="Math operations")

    math_subparsers = math_parser.add_subparsers(
        dest = "math_command",
        required = True
    )

    add_parser = math_subparsers.add_parser("add", help = "Add nums")
    add_parser.add_argument("numbers", nargs="+", type=float, help="Numbers to add")
    add_parser.set_defaults(func=add_nums)

    mult_parser = math_subparsers.add_parser("mul", help = "Multiply nums")
    mult_parser.add_argument("numbers", nargs="+", type=float, help="Numbers to multiply")
    mult_parser.set_defaults(func=multiply_nums)

def add_nums(args):
    res = sum(args.numbers)
    print(f"result: {res}")
    
def multiply_nums(args):
    res = 1
    for n in args.numbers:
        res *= n
    print(f"result: {res}")
    
