from abc import ABC, abstractmethod

class LaunchAgency:
    def __init__(self, name) -> None:
        self.name = name
        self.observers = []

    def subscribe(self, sub):
        self.observers.append(sub)
    
    def notify(self, launch):
        for sub in self.observers:
            sub.sendNotification(self.name, launch)

class LaunchViewer(ABC):
    @abstractmethod
    def sendNotification(self, launch):
        pass

class User(LaunchViewer):
    def __init__(self, name) -> None:
        self.name = name
    
    def sendNotification(self, agency, launch):
        print(f"User: {self.name} received notification from\n{agency} for ---> {launch}")

agency = LaunchAgency("SpaceX")

agency.subscribe(User("Viewer 1"))
agency.subscribe(User("Viewer 2"))
agency.subscribe(User("Viewer 3"))

agency.notify("Starship Flight 11")

