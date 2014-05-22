type a19 = (string * (string list)) list
let rec a10 (a7 : a19)  (a8 : string) : a19 =
  match a7 with
  | [] -> [(a8, [])]
  | (name, _) :: tail when name = a8 -> a7
  | head :: tail -> head :: (a10 tail a8)
;;
let rec a11 (a7 : a19)  (a1 : string) (a2 : string): a19 =
  match a7 with
  | [] -> [(a1, [a2])]
  | (name, dependencies) :: tail when name = a1 -> (name, a2 ::
                                                            dependencies) :: tail
  | head :: tail -> head :: (a11 tail a1 a2)
;;
let rec a12 (a3 : string list) : a19 =
  match a3 with
  | [] -> []
  | a1 :: (a2 :: tail) ->
     let a7 = a12 tail in
     a11 (a10 a7 a2) a1
         a2
  | a1 :: tail -> []
;;
let rec a13 (a7 : a19) (a4 : string) =
  match a7 with
  | [] -> a4
  | (name, dependencies) :: tail when (dependencies = [] && (a4 = "" || (compare a4
                                                                                 name) < 0)) -> a13 tail name
  | head :: tail -> a13 tail a4
;;
let rec a14 (a7 : a19)  (a8 : string) : a19 =
  match a7 with
  | [] -> []
  | (name, _) :: tail when name = a8 -> tail
  | head :: tail -> head :: (a14 tail a8)
;;
let rec a15 (a5 : 'a list) (a6 : 'a) : 'a list=
  match a5 with
  | [] -> []
  | head :: tail when head = a6 -> a15 tail a6
  | head ::tail -> head :: (a15 tail a6)
;;
let rec a16 (a7 : a19)  (a8 : string) : a19 =
  match a7 with
  | [] -> []
  | (name, dependencies) :: tail -> (name, (a15 dependencies a8)) ::
                                      (a16 tail a8)
;;
let rec a17 (a7 : a19) : string list =
  if a7 = []
  then
    []
  else
    let a8 = a13 a7 "" in
    if a8 = ""
    then
      raise (Failure "cycle")
    else
      a8 :: a17 (a16 (a14 a7
                          a8) a8)
;;
let rec a18 (a9 : string list) : unit =
  match a9 with
  | [] -> ()
  | head :: [] -> print_endline head
  | head :: tail -> a18 tail; print_endline head
;;
let a3 = ref [] in
    try
      while true do
        a3 := (read_line()) :: !a3
      done
    with _ -> begin
        let a7 = a12 !a3 in
        try
          let a9 = a17 a7 in
          a18 a9
        with Failure _ -> print_endline "cycle\r"
      end
