#pylint: skip-file
#type: ignore

def downsample(samples, step):
    return samples[::step]

if __name__ == "__main__":
    samples = [(i, i*0.1) for i in range(100)]
    down_sampled = downsample(samples=samples, step=10) 
    print(*down_sampled, sep="\n")    