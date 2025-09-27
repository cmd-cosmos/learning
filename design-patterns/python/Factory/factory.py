### Creational Pattern

class Rocket:
    def __init__(self, components) -> None:
        self.components = components

    def print(self):
        print(self.components)

class RocketFactory:
    def createFalcon9(self):
        components = ["8 + 1 - Merlin 1D", "Stage 1", "Stage 2", "Landing Legs"]
        return Rocket(components=components)
    
    def createFalconHeavy(self):
        components = ["24 + 1 - Merlin 1D", "Center Core", "Side Boosters", "Landing Legs"]
        return Rocket(components=components)
    
    def createStarship(self):
        components = ["33 + 6 - Raptor", "Booster", "Ship", "Flaps"]
        return Rocket(components=components)
    
rocketFactory = RocketFactory()

rocketFactory.createFalcon9().print()
rocketFactory.createFalconHeavy().print()
rocketFactory.createStarship().print()