### More customizable factory pattern

class Rocket:
    def __init__(self) -> None:
        self.engines = None
        self.stage = None
        self.stage2 = None
    
    def setEngine(self, engineStyle):
        self.engines = engineStyle

    def setStage(self, stageStyle):
        self.stage = stageStyle

    def setStage2(self, stage2Style):
        self.stage2 = stage2Style

class RocketBuilder:
    def __init__(self) -> None:
        self.rocket = Rocket()
    
    def addEngine(self, engineStyle):
        self.rocket.setEngine(engineStyle=engineStyle)
        return self
    
    def addStage(self, stageStyle):
        self.rocket.setStage(stageStyle=stageStyle)
        return self
    
    def addStage2(self, stage2Style):
        self.rocket.setStage2(stage2Style=stage2Style)
        return self
    
    def build(self):
        return self.rocket
    
    
rocket = RocketBuilder().addEngine("Merlin").addStage("Lander")\
                        .addStage2("Payload Stage").build()

print(rocket.engines)
print(rocket.stage)
print(rocket.stage2)
