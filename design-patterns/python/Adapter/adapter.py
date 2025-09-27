class Booster:
    def __init__(self) -> None:
        self.isMounted = False
    
    def mountBooster(self):
        self.isMounted = True

class Mount:
    def __init__(self):
        self.mountAvailable = True
    
    def mount(self, booster):
        if self.mountAvailable:
            booster.mountBooster()
            self.mountAvailable = False

booster = Booster()
olm = Mount()
olm.mount(booster=booster)

class Starship:
    def __init__(self) -> None:
        self.isMounted = False
    
    def mountStarship(self):
        self.isMounted = True

class shipAdapterRing(Booster):
    def __init__(self, starship):
        self.starship = starship
        self.starship.mountStarship()

shipRingAdapter = (shipAdapterRing(Starship()))
mount2 = Mount()
mount2.mount(shipRingAdapter) 