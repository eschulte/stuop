let a20 (a17:string list) (a18:(string*string) list) =
  List.filter
    (fun a4 ->
     (List.length (List.filter (fun (a3, a7) -> a4 = a7) a18)) == 0)
    a17
;;
let rec a21 (a17:string list) (a18:(string*string) list)
            (acc:string list) =
  match a17 with
  | [] -> acc
  | a3 ->
     (let a1 = List.sort String.compare (a20 a17 a18) in
      match a1 with
      | [] -> []
      | a3 ->
         let a2 = List.hd a1 in
         let a13 =
           List.filter (fun (a6, a3) -> a6 <> a2) a18 in
         let a9 =
           List.filter (fun a4 -> a4 <> a2) a17 in
         let a5 = acc@[a2] in
         a21 a9 a13 a5
     )
;;
let a22 (a17:string list) (a18:(string*string) list) =
  a21 a17 a18 [];;
let rec a23 (a16:string list)
            ((a17:string list), (a18:(string*string) list)) =
  match a16 with
  | [] -> (a17, a18)
  | a3 ->
     let a6 = List.hd a16 in
     let a7 = List.hd (List.tl a16) in
     let a8 = List.tl (List.tl a16) in
     let a9 =
       if List.exists (fun a10 -> a6 = a10) a17
       then a17
       else a6::a17
     in
     let a11 =
       if List.exists (fun a12 -> a7 = a12) a9
       then a9
       else a7::a9
     in
     let a13 =
       if List.exists (fun (a14, a15) -> a6 = a14 && a7 = a15) a18
       then a18
       else (a6, a7)::a18
     in
     a23 a8 (a11, a13)
;;
let a24 (a16:string list) = a23 a16 ([], []);;
let a16 = ref [] in
    try
      while true do
        a16 := (read_line ()) :: !a16
      done
    with a3 -> begin
        let a17, a18 = a24 !a16 in
        let a19 = a22 a17 a18 in
        match a19 with
        | [] -> print_endline "cycle"
        | a3 -> List.iter print_endline a19
      end
;;
