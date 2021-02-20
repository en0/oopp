from typing import List

from .typing import PresentationTopic


class HowCanILearnMore(PresentationTopic):
    """The best way to learn a tool is to use it.

    You will get better with practice. But it also helps to get some
    instruction from people that know what they are talking about.
    """

    links: List[str]

    def examine(self):

        self.links = [
            "https://dpc.pw/the-faster-you-unlearn-oop-the-better-for-you-and-your-software",
            "https://github.com/bethrobson/Head-First-Design-Patterns",
            "https://programmingwithmosh.com/net/common-mistakes-with-the-repository-pattern/",
            "https://refactoring.guru/",
            "https://www.geeksforgeeks.org/solid-principle-in-programming-understand-with-real-life-examples/",
            "http://f.javier.io/rep/books/The%20Elements%20of%20Computing%20Systems.pdf"
        ]

        return super().examine()
