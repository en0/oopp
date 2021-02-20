from abc import ABC, abstractmethod
import textwrap


class PresentationTopic(ABC):
    """Here is my challenge to you!

    Use OOP concepts to make this print strings in a few formats. 
    Assume the user will be able to select what output format as a
    command line argument.

    Hint: extract what changes, leave what doesn't

    How much your solution change if the feature required to allow
    configuration information for each output format?
    """

    def _format_doc(self):
        doc = " ".join([s.lstrip() for s in self.__doc__.split("\n")])
        return textwrap.fill(doc, 80)

    def examine(self):
        print(f"## {self.__class__.__name__}\n")
        print(self._format_doc())
        print("")
        self._next_topic.examine()

    def __init__(self, next_topic: "PresentationTopic"):
        self._next_topic = next_topic
