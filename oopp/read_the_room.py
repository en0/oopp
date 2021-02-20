from typing import List

from .topic_base import PresentationTopic


class ReadTheRoom(PresentationTopic):
    """I assume we all dislike OOP.

    That might not be fair. In fact, I love OOP. So i know the assumption is not
    accurate. But it's at least a place to start.
    """

    question: str
    answers: List[str]

    def examine(self):

        self.question = "What is wrong with OOP?"

        self.answers = [
            # Lets talk about it.
        ]

        return super().examine()
