from typing import List

from .typing import PresentationTopic


class WhatItIsNot(PresentationTopic):
    """Dont get hung up on the wrong thing.

    The point is to control complexity, not to follow rules.
    The rules are given to keep the car between the lines, not
    to get you to your destination, that part is up to you.
    """

    question: str
    answers: List[str]

    def examine(self):

        # Some rules make sense until they dont.
        self.rules = [
            "DRY",
            "Single Responsibility",
            "Tell, Don't Ask",
        ]

        # Other rules are just garbage.
        # They only exist as a means of gate keeping.
        self.rules += [
            "Find the right pattern",
            "If it's not working, your doing it wrong.",
            "Encapsulate Everything",
        ]

        if not self.follow_rules():
            # Because "real developers"...
            raise NotRealOopException()

        return super().examine()

    def follow_rules(self) -> bool:
        ...

