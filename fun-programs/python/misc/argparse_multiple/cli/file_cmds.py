#pylint: skip-file

from utils.validators import existing_file

def register_file_cmd(subparsers):
    file_parser = subparsers.add_parser("file", help="file utils")

    file_subparsers = file_parser.add_subparsers(dest="file_command", required=True)

    count_parser = file_subparsers.add_parser("count-lines", help="count lines in a file")

    count_parser.add_argument("path", type=existing_file, help="path to a text file")

    count_parser.add_argument("--ignore-empty", action="store_true", help="ignore empty lines")

    count_parser.set_defaults(func=count_lines)

def count_lines(args):
    with open(args.path, "r") as f:
        lines = f.readlines()

    if args.ignore_empty:
        lines = [l for l in lines if l.strip()]
    
    print(f"lines: {len(lines)}")