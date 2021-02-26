from functools import reduce

from .null_topic import NullTopic
from .read_the_room import ReadTheRoom
from .back_to_basics import BackToBasics
from .what_it_is_not import WhatItIsNot
from .show_me import ShowMeWhatYouMean
from .learn_more import HowCanILearnMore
from .topic_base import PresentationTopic, HTMLFormatter, Formatter


class Presentation:
    """A discussion on Object Oriented Programming.

    I would like to talk about Object Oriented Programming. I would like to know your
    thoughts and experiences. I would like to know your pain and successes.

    Really, I just want to nerd out about OOP. I hope to be able to leave hear with
    a more complete picture of OOP and share the knowledge I have with each of you.
    """

    def examine(self):
        self._formatter.open()
        self._parts.examine()
        self._formatter.close()

    def __init__(self, formatter: Formatter):

        self._formatter = formatter
        PresentationTopic.formatter = formatter

        self._parts = reduce(lambda a, b: b(a), reversed([
            ReadTheRoom,
            BackToBasics,
            WhatItIsNot,
            ShowMeWhatYouMean,
            HowCanILearnMore,
        ]), NullTopic())


if __name__ == "__main__":
    html_formatter = HTMLFormatter()
    pres = Presentation(html_formatter)
    pres.examine()

