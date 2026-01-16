# pylint: skip-file

import argparse

def create_parser():
    parser = argparse.ArgumentParser(prog = "CLIproj",
                                     description =  "A sample CLI for understanding argparse.")
    parser.add_argument(
        "-v", "--verbose", action="count", default=0, help="Increase verbosity (-v, -vv, -vvv)"
    )

    subparsers = parser.add_subparsers(
        title="commands",
        dest="command"
    )

    return parser

