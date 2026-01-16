#pylint: skip-file

from cli.parser import create_parser

def main():
    parser = create_parser()
    args = parser.parse_args()

    if hasattr(args, "func"):
        args.func(args)
    else:
        parser.print_help()

if __name__ == "__main__":
    main()