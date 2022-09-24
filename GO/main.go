package main

import (
	"fmt"
	"log"
	"net/http"

	"simplehttpserver.com/http/httphandlers"
)

func main() {

	fmt.Println(ServerStart)

	ServeStaticFile := http.FileServer(http.Dir("./FILES"))

	http.Handle("/", ServeStaticFile)
	http.HandleFunc("/whatever", httphandlers.HandleHttpGET)
	http.HandleFunc("/postForm", httphandlers.HandleHttpPOST)
	http.HandleFunc("/purge", httphandlers.Purge)

	err := http.ListenAndServe(Port, nil)
	if err != nil {
		log.Fatal(err)
	}

}
