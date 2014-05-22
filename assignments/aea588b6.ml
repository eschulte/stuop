let a15 a14 a12 =
  (List.length (List.filter ((fun a13 (a1,a2) -> ((compare (a13) (a2))==0)) a12) a14)) ==0;;
let rec a16 a3 a4 =
  match a3 with
  | [] -> []
  | _ -> (
    let a5 = List.hd (List.sort (compare) (List.filter (a15 a4) a3)) in
    a5::(a16 (List.filter ((fun a14 a12 -> ((compare a14 a12)!=0)) a5) a3) (List.filter ((fun a13 (a14,a12) -> (( (compare a14 a13)!=0 ) && ( (compare a12 a13)!=0))) a5) a4))
  );;
let a17 a6 =
  let a7 = Hashtbl.create (List.length a6) in
  List.iter (fun a8 -> Hashtbl.replace a7 a8 ()) a6;
  Hashtbl.fold (fun a8 () a9 -> a8 :: a9) a7 [];;
let a10 = ref [] in
    try
      while true do
        a10 := (read_line (), read_line ()) :: !a10
      done
    with _ -> begin
        let a11 = a17 (List.fold_left (fun a14 (a12,a13) -> a12::a13::a14) [] !a10) in
        try
          List.iter (fun a14 -> print_endline (a14 ^ "")) (a16 a11 !a10);
        with err -> begin
            print_endline "cycle\r";
          end
      end
