class Dragon {
    void attack()
    {
        System.out.println("[DRAGON ATTACKED] Fire Breath");
    }
}
class ElectroDragon extends Dragon {
    @Override
    void attack()
    {
        System.out.println("[ELECTRO DRAGON ATTACKED] Electro Zap");
    }
}

public class Inherit{
    public static void main(String[] args)
    {
        Dragon dragon = new Dragon();
        dragon.attack();
        ElectroDragon eDragon = new ElectroDragon();
        eDragon.attack();
    }
}