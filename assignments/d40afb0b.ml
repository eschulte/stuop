open String;;
exception A1;;
let a18 a2 a3 a12 = a3 (a2 a12);;
let rec a19 a7 =
  match a7 with
  | [] -> []
  | head :: tail ->
     head :: a19 (List.filter ((<>) head) tail);;
let a20 a9 =
  let a4 = List.map fst a9 in
  let a5 = List.map snd a9 in
  a19 a4 @ a5;;
let a21 a9 a6 =
  List.filter (fun a12 -> not (List.mem a12 (List.map fst a9))) a6
let a22 a7 a8 =
  List.filter ((<>) a8) a7
let rec a23 (a9 : (string * string) list) (free_vertices : string list) : string list =
  match a9 with
  | [] -> List.sort compare free_vertices
  | a9 ->
     match free_vertices with
     | [] -> raise A1
     | free_vertex :: _ ->
        let a10 = List.filter (fun a12 -> snd a12 <> free_vertex) a9 in
        let a11 = List.map fst (List.filter (fun a12 -> snd a12 = free_vertex) a9) in
        let a13 = a19 (free_vertices @ (a21 a10 a11)) in
        let a13 = a22 a13 free_vertex in
        let a13 = List.sort compare a13 in
        free_vertex :: a23 a10 a13;;
let a24 a14 =
  a23 a14 (List.sort compare (a21 a14 (a20 a14)));;
let a25 a17 =
  List.iter print_endline a17
let a26 () =
  print_endline "cycle";;
let a14 = ref [] in
    try
      while true do
        let a15 = read_line () in
        let a16 = read_line () in
        a14 := (a15, a16) :: !a14
      done
    with _ -> begin
        try
          let a17 = a24 !a14 in
          a25 a17
        with
        | A1 -> a26 ()
      end
