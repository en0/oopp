from .typing import PresentationTopic


class NullTopic(PresentationTopic):

    def examine(self):
        ...

    def __init__(self):
        ...

