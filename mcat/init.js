class PcmObject {
    constructor() {
        this.pcm = null; // Initialize pcm to null
        this.connected = false; // Initialize connected to false
        this.rpcs_addr = "localhost:41000";
    }

    onSocketConnected() {
        this.connected = true;
        console.log("Connected to freeMASTER");
        if (this.pcm) {
            this.pcm.EnableEvents(true);
        }
    }

    onSocketClose() {
        this.connected = false;
        console.warn("Socket closed");
    }

    onSocketError(err) {
        this.connected = false;
        console.error("Socket error: ", err.message);
    }

    onServerError(err) {
        this.connected = false;
        console.error("Server error: ", err.message);
    }

    startPcm() {
        if (!this.pcm) {
            if (typeof FreeMASTER !== "undefined") {
                this.rpcs_addr = FreeMASTER.rpcs_addr;
            } else {
                console.log("FreeMASTER is undefined, loading the default port...");
            }
            this.pcm = new PCM(
                this.rpcs_addr,
                this.onSocketConnected.bind(this), // Ensure 'this' refers to the class instance
                this.onSocketClose.bind(this),
                this.onSocketError.bind(this)
            );
            this.pcm.OnServerError = this.onServerError.bind(this);
            this.pcm.OnSocketError = this.onSocketError.bind(this);
        } else {
            console.log("Already connected to freeMASTER");
        }
    }

// async waitUntilConnected(attempts) {
//         for (let i = 0; i < attempts; i++) {
//             if (!this.connected) {
//                 console.log("Not connected yet, let's wait...");
//                 await ;new Promise(resolve => setTimeout(resolve, 500));
//             } else {
//                 return;
//             }
//         }
//         throw new Error("Unable to connect to freeMASTER after " + attempts + " attempts");
//     }

//         throw (new Error("Unable to connect to freeMASTER after 10 times"));
//     }

    // async isCommPortOpen() {
    //     await this.waitUntilConnected(10);
    //     return this.pcm.IsCommPortOpen();
    // }

    // Other methods follow...
}

