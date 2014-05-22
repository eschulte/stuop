let rec a14 a12 =
  try
    let a1 = read_line() in
    a14 ((a1, read_line())::a12)
  with
    a9 -> a12
;;
module A21 = Set.Make(String);;
module A22 = Map.Make(String);;
let a15 () =
  let a2 = a14 [] in
  let a16 a3 a13 = A21.add (snd a13) (A21.add (fst a13) a3) in
  let a4 = List.fold_left a16 A21.empty a2 in
  let a17 a10 a5 =
    let a18 a12 a13 =
      match a13 with
	(fst, snd) when fst=a10 -> snd::a12
      | a9 -> a12 in
    let a11 = List.fold_left a18 [] a2 in
    A22.add a10 a11 a5 in
  let a6 = A21.fold a17 a4 A22.empty in
  let rec a19 a6 a7 =
    try
      let a8, a9 = List.hd (A22.bindings (A22.filter (fun a10 a11 -> (List.length a11)=0) a6)) in
      let a20 a12 =
	List.filter (fun a13 -> a13<>a8) a12
      in
      a19 (A22.map a20 (A22.remove a8 a6)) (a8::a7)
    with
      a9 -> match A22.is_empty a6 with
	      true -> List.iter (fun a13 -> print_string(a13); print_newline()) (List.rev a7)
            | false -> print_string("cycle"); print_newline()
  in
  a19 a6 [];
  exit 0;;
  a15 ();;
