package httphandlers

import (
	"encoding/json"
	"fmt"
	"net/http"
	"os"
	"time"

	FileMan "simplehttpserver.com/http/FileMan"
)

type WritableMessageBOody struct {
	Identity string
	Message  string
	Date     string
}

func HandleHttpGET(w http.ResponseWriter, r *http.Request) {

	println(r.URL.Path)

	var wmessage WritableMessageBOody

	err := json.NewDecoder(r.Body).Decode(&wmessage)

	if err != nil {
		fmt.Println(err.Error())
		http.Error(w, "BAD REQUEST ", http.StatusBadRequest)
		return
	}

	if r.Method != "GET" {
		http.Error(w, "METHOD NOT SUPPORTED", http.StatusNotFound)
		return
	}

	if r.URL.Path != "/v1/Get/Message" {
		http.Error(w, "404 NOT FOUND", http.StatusBadRequest)
		return
	}

	response := FileMan.ReadFromFile(wmessage.Identity)

	fmt.Fprintf(w, response)

}

func HandleHttpPOST(w http.ResponseWriter, r *http.Request) {

	println(r.URL.Path)

	t := time.Now()

	var wmessage WritableMessageBOody

	err := json.NewDecoder(r.Body).Decode(&wmessage)

	if err != nil {
		fmt.Println(err.Error())
		http.Error(w, "BAD REQUEST ", http.StatusBadRequest)
		return
	}

	if r.Method != "POST" {
		http.Error(w, "METHOD NOT SUPPORTED", http.StatusNotFound)
		return
	}

	if r.URL.Path != "/v1/Post/Message" {
		http.Error(w, "404 NOT FOUND", http.StatusBadRequest)
		return
	}

	FileMan.WritetoFile(t.String(), wmessage.Message, wmessage.Identity)

	fmt.Fprintln(w, "200 OK")

}

func HandleHttpPut(w http.ResponseWriter, r *http.Request) {

	println(r.URL.Path)

	t := time.Now()

	var wmessage WritableMessageBOody

	err := json.NewDecoder(r.Body).Decode(&wmessage)

	if err != nil {
		fmt.Println(err.Error())
		http.Error(w, "BAD REQUEST ", http.StatusBadRequest)
		return
	}

	if r.Method != "PUT" {
		http.Error(w, "METHOD NOT SUPPORTED", http.StatusNotFound)
		return
	}

	if r.URL.Path != "/v1/Put/Message" {
		http.Error(w, "404 NOT FOUND", http.StatusBadRequest)
		return
	}

	FileMan.AppendtoFile(t.String(), wmessage.Message, wmessage.Identity)

	fmt.Fprintln(w, "200 OK")

}

func HandleHttpPurge(w http.ResponseWriter, r *http.Request) {
	fmt.Println(r.URL.Path)
	if r.Method != "POST" {
		http.Error(w, "METHOD NOT SUPPORTED", http.StatusNotFound)
		return
	}

	if r.URL.Path != "/v1/Post/Purge" {
		http.Error(w, "404 NOT FOUND", http.StatusBadRequest)
		return
	}
	runPurge()
}

func runPurge() {
	err := os.Remove("./FILES")
	if err != nil {
		panic(err.Error())
	} else {
		fmt.Println("PURGE SUCESSFULL")
	}

}
