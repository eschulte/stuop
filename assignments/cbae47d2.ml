let rec a13 a5 =
  match a5 with
  | [] -> []
  | x :: xs -> [x; (List.hd xs)] :: a13 (List.tl xs)
;;
let rec a14 a7 a6 =
  match a6 with
  | [] -> ()
  | x :: xs -> let a1 = try (Hashtbl.find !a7 (List.hd x)) with Not_found -> 0 in
               let a2 = try (Hashtbl.find !a7 (List.nth x 1)) with Not_found -> 0 in
               Hashtbl.replace !a7 (List.hd x) (a1 + 1);
               Hashtbl.replace !a7 (List.nth x 1) a2;
               a14 a7 xs
;;
let rec a15 a8 a6 =
  match a6 with
  | [] -> ()
  | x :: xs -> Hashtbl.add !a8 (List.nth x 1) (List.hd x);
               a15 a8 xs
;;
let a16 a7 =
  let a10 = ref "" in
  Hashtbl.iter (fun a3 a4 -> if a4 = 0 && (!a10 = "" || a3 < !a10) then a10 := a3) !a7;
  !a10
;;
let a5 = ref [] in
    try
      while true do
        a5 := !a5 @ [read_line ()]
      done
    with _ -> begin
        let a6 = a13 !a5 in
        let a7 = ref (Hashtbl.create 31415) in
        let a8 = ref (Hashtbl.create 31415) in
        a14 a7 a6;
        a15 a8 a6;
        let a9 = ref [] in
        let a10 = ref "" in
        let a11 = ref 0 in
        while (Hashtbl.length !a7) > 0 && !a11 = 0 do
          a10 := (a16 a7);
          if (!a10 = "") then (
            a11 := 1;
            print_endline "cycle";
          ) else (
            a9 := !a9 @ [!a10];
            Hashtbl.remove !a7 !a10;
            List.iter (fun a12 -> (Hashtbl.replace !a7 a12 ((Hashtbl.find !a7 a12) - 1))) (Hashtbl.find_all !a8 !a10);
          );
          if ((Hashtbl.length !a7) = 0 && !a11 = 0) then
            List.iter print_endline !a9;
        done
      end
