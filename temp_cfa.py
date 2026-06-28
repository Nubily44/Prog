import threading

class NFC_Scanner:
    def __init__(self):
        self.request = threading.Event()
        self.done = threading.Event()

    def emit(self):
        # Limpa o evento de conclusão
        self.done.clear()

        # Solicita a leitura NFC
        self.request.set()

        # Espera até o listener processar a solicitação
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
        # Espera por um evento de solicitação NFC
        nfc.request.wait()
        
        # Limpa o evento de solicitação para a próxima leitura
        nfc.request.clear()

        print("NFC Send")

        livres = SearchAssento(Assentos)

        for assento in livres:
            assento.bipar()

        # Notifica que a leitura NFC foi processada
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