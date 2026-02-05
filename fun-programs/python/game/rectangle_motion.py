# pylint:skip-file
# type:ignore

import pygame
import sys  

pygame.init()

WIDTH, HEIGHT = 800,600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("rectangle motion")

clock = pygame.time.Clock()

rect_wh, rect_ht = 50, 50 
rectx, recty = WIDTH // 2, HEIGHT // 2
rect_speed = 5

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()

    if keys[pygame.K_LEFT]:
        rectx -= rect_speed
    if keys[pygame.K_RIGHT]:
        rectx += rect_speed
    if keys[pygame.K_UP]:
        recty -= rect_speed
    if keys[pygame.K_DOWN]:
        recty += rect_speed
    
    rectx = max(0, min(WIDTH - rect_wh, rectx))
    recty = max(0, min(HEIGHT - rect_ht, recty))

    screen.fill((0,0,0))
    pygame.draw.rect(screen, (255,0,0), (rectx, recty, rect_wh, rect_ht))
    
    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()