# pylint: skip-file

import argparse
from cli.math_subcommands import register_math_cmd

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

    register_math_cmd(subparsers=subparsers)

    return parser

