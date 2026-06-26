import threading


class NFC_Scanner:
    def __init__(self):
        self.request = threading.Event()
        self.done = threading.Event()

    def emit(self):
        # Prepare for a new request
        self.done.clear()

        # Notify listener
        self.request.set()

        # Wait until listener finishes
        self.done.wait()

class Assento:
    def __init__(self, id):
        print(f"Assento {id} criado.")
        self.id = id
        self.ocupado = False

    def ocupar(self):
        self.ocupado = True

    def bipar(self):
        if not self.ocupado:
            print(f"Assento {self.id} livre. BIP BIP!")


def SearchAssento(assentos):
    return [a for a in assentos if not a.ocupado]


def listen(nfc):
    while True:
        # Wait for an NFC scan
        nfc.request.wait()
        nfc.request.clear()

        print("NFC Send")

        livres = SearchAssento(Assentos)

        for assento in livres:
            assento.bipar()

        # Notify the emitter that processing is complete
        nfc.done.set()


def listener(nfcs):
    threads = []

    for nfc in nfcs:
        t = threading.Thread(target=listen, args=(nfc,), daemon=True)
        t.start()
        threads.append(t)

    return threads


if __name__ == "__main__":
    nfc1 = NFC_Scanner()
    nfc2 = NFC_Scanner()

    nfcs = [nfc1, nfc2]

    Assentos = [Assento(i) for i in range(5)]

    Assentos[1].ocupar()
    Assentos[3].ocupar()

    listener(nfcs)

    # First NFC scan
    nfc1.emit()

    # Seat becomes occupied only after the first scan finishes
    Assentos[0].ocupar()

    # Second NFC scan
    nfc2.emit()