from typing import List

from .topic_base import PresentationTopic


class ShowMeWhatYouMean(PresentationTopic):
    """OOP is about complexity control.

    I have some examples i would like to share with you.
    While looking at these, think about how complexity is managed. How might the code
    grow over time? Does it provide a simple enough pattern to evolve in a predictable
    way in a large team?

    Ask questions, offer alternatives, tell me i spelled things wrong.
    """

    worries: str
    guidlines: List[str]
    examples: List[str]

    def examine(self):

        self.worries = [
            "If i see one more duck interface and quack behavior...",
        ]

        # here are some "rules" to think about when looking at these examples.
        self.guidlines = [
            "Write code to an interface, not an implementation.",
            "Interchangeable behaviors warrant encapsulation.",
            "Data is the central purpose.",
        ]

        self.examples = [
            "examples/boot_loader.S",
            "examples/log.h"
            "examples/log.c"
            "examples/serial_8250.h"
            "examples/main.c"
            "oopp/topic_base.py",
        ]

        return super().examine()
