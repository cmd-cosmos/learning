#pylint: skip-file
#type: ignore

import argparse

def main():
    parser = argparse.ArgumentParser()

    parser.add_argument("--a", default=1, type=int, help="inp 1, default = 1.")
    parser.add_argument("--b", default=1, type=int, help="inp 2, default = 1.")
    parser.add_argument("--verbose", required=False, action="store_true")

    args = parser.parse_args()

    res = args.a * args.b
    if args.verbose:
        print(f"Multiplying: {args.a} and {args.b}")
        print(f"result: {res}")
    else:
        print(res)

if __name__ == "__main__":
    main()

