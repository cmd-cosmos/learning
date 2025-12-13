#pylint: skip-file
#type: ignore

import argparse

def main():
    parser = argparse.ArgumentParser()

    parser.add_argument("--i1", default=0, type=int, required=False, help="num 1, default val = 0")
    parser.add_argument("--i2", default=0, type=int, required=False, help="num 2, default val = 0")
    
    args =parser.parse_args()

    res = args.i1 + args.i2
    print(res)
    

if __name__ == "__main__":
    main()