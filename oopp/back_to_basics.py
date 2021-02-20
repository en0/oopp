from typing import List

from .topic_base import PresentationTopic


class BackToBasics(PresentationTopic):
    """What problems does OOP solve?

    OOP does have a reason to exist behond just giving us rules.

    In "The Elements of Computing Systems: Building a Modern Computer from First Principles"
    the authors, Noam Nisan ans Shimon Schacken, focus a lot on the abstraction/implementation
    paradigm. They refer to this ability to create abstractions "A special gift unique to humans".

    Speaking about the abstraction/implementation approach, the authors continued:

    "This typical modular rendition of a multi-tier system represents not only a
    powerful engineering paradigm, but also a central dogma in human reasoning,
    going back at least 2,500 years"

    Our brains are built to think in abstraction.
    """

    question: str
    answers: List[str]

    def examine(self):

        self.question = "What problems is OOP trying to solve?"

        self.answers = [
            # Lets talk about it.
        ]

        return super().examine()
