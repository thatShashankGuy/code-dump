package httphandlers

import (
	"encoding/json"
	"fmt"
	"net/http"
	"os"

	FileMan "simplehttpserver.com/http/FileMan"
)

type WritableJSONBody struct {
	Add string
	Pin string
}

func HandleHttpGET(res http.ResponseWriter, req *http.Request) {

	if req.Method != "GET" {
		http.Error(res, "METHOD NOT SUPPORTED", http.StatusNotFound)
		return
	}

	if req.URL.Path != "/whatever" {
		http.Error(res, "404 NOT FOUND", http.StatusBadRequest)
		return
	}

	fmt.Fprintln(res, "WHATEVER COMEBACKS!")

}

func HandleHttpPOST(res http.ResponseWriter, req *http.Request) {

	var wbod WritableJSONBody

	err := json.NewDecoder(req.Body).Decode(&wbod)

	if err != nil {
		fmt.Println(err.Error())
		http.Error(res, "BAD REQUEST ", http.StatusBadRequest)
		return
	}

	if req.Method != "POST" {
		http.Error(res, "METHOD NOT SUPPORTED", http.StatusNotFound)
		return
	}

	if req.URL.Path != "/postForm" {
		http.Error(res, "404 NOT FOUND", http.StatusBadRequest)
		return
	}
	fmt.Fprintln(res, "200 OK")

	fmt.Println(wbod)
	FileMan.WritetoFILES(wbod.Add, wbod.Pin)
}

func Purge(w http.ResponseWriter, r *http.Request) {
	if r.Method != "POST" {
		http.Error(w, "METHOD NOT SUPPORTED", http.StatusNotFound)
		return
	}

	if r.URL.Path != "/purge" {
		http.Error(w, "404 NOT FOUND", http.StatusBadRequest)
		return
	}
	runPurge()

	fmt.Fprintln(w, "200 OK - FOLDER IS EMPTY NOW ")
}

func runPurge() {
	err := os.Remove("./FILES/FLAT-FILES/")
	if err != nil {
		panic(err.Error())
	} else {
		fmt.Println("PURGE SUCESSFULL")
	}

}
