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
	http.HandleFunc("/v1/Get/Message", httphandlers.HandleHttpGET)
	http.HandleFunc("/v1/Post/Message", httphandlers.HandleHttpPOST)
	http.HandleFunc("/v1/Post/Purge", httphandlers.HandleHttpPurge)
	http.HandleFunc("/v1/Put/Message", httphandlers.HandleHttpPut)

	err := http.ListenAndServe(Port, nil)
	if err != nil {
		log.Fatal(err)
	}

}
