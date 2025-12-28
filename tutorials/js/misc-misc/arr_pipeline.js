const characters = [
    {name: "Batman", health: 100},
    {name: "Joker", health: 25},
    {name: "Riddler", health: 75},
    {name: "Scarecrow", health: 48},
];

const avg_health = characters.filter(characters => characters.health  >= 50).map(characters => characters.health).reduce((sum, health, _, arr) => sum + health / arr.length, 0)

console.log(avg_health)
