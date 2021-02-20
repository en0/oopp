from abc import ABC, abstractmethod


class PresentationTopic(ABC):

    def examine(self): ...
        self._next_topic.examine()

    def __init__(self, next_topic: "PresentationTopic"):
        self._next_topic = next_topic
